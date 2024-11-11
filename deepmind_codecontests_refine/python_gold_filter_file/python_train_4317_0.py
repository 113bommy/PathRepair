num_piles = int(input())
worm_piles = list(map(int, input().split()))
num_juicy_worms = int(input())
juicy_worm_labels = list(map(int, input().split()))

bins = []  # ith num is min for the bin
running_sum = 1
for i in range(1, num_piles + 1):
    if i == 1:
        bins.append(running_sum)
        running_sum += worm_piles[i - 1]
    else:
        bins.append(running_sum)
        running_sum += worm_piles[i - 1]

# Output the bin the juicy worms are in
last_bin_idx = num_piles - 1
for juicy_worm_label in juicy_worm_labels:
    if juicy_worm_label >= bins[last_bin_idx]:  # don't need to do binary search since it's last
        print(last_bin_idx + 1)
        continue

    mn = 0
    mx = last_bin_idx
    while mn <= mx:
        mid_idx = (mn + mx) // 2

        if bins[mid_idx] <= juicy_worm_label < bins[mid_idx + 1]:
            print(mid_idx + 1)
            break

        if juicy_worm_label > bins[mid_idx]:  # want to check greater vals
            mn = mid_idx + 1 #if mn != mid_idx else mn + 1
        else:  # want to check lower vals
            mx = mid_idx - 1 #if mx != mid_idx else mx - 1
        # print('worm label: {}, mn: {}, mx: {}'.format(juicy_worm_label, mn, mx))

    # for i in range(num_piles):
    #     if juicy_worm_label >= bins[last_bin_idx]:
    #         print(last_bin_idx + 1)
    #         break
    #     elif bins[i] <= juicy_worm_label < bins[i + 1]:
    #         print(i + 1)
    #         break
