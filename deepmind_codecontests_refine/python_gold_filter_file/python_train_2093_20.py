l = int(input())
a = input()
all_sum = 0
for i in a:
    all_sum += int(i)
fl = False
for i in range(2, all_sum + 3):
    if all_sum % i == 0:
        num_s = 0
        fl = True
        for j in a:
            num_s += int(j)
            if num_s == all_sum // i:
                num_s = 0
            elif num_s > all_sum // i:
                fl = False
                break
        if (num_s < all_sum // i) and (num_s != 0):
            fl = False
        if fl:
            break
if fl:
    print("YES")
else:
    print("NO")