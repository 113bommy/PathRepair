# import time
def helper(dl, H):
    min_index, min_value = 0, 0
    acc_sum = 0
    kill_index = -1
    kill_flag = True
    for i in range(len(dl)):
        acc_sum += dl[i]
        if kill_flag and acc_sum + H <= 0:
            kill_index = i + 1
            kill_flag = False
        if acc_sum < min_value:
            min_value = acc_sum
            min_index = i
    return min_value, min_index + 1, kill_index, dl[min_index + 1:] + dl[:min_index + 1]

def solve(H, dl):
    dH, n, kill_index, dl = helper(dl, H)
    if H + dH <= 0:
        return kill_index
    H += dH
    # print('dl:', dl)
    # print('H:', H)
    round_drop = sum(dl)
    if round_drop >= 0:
        return -1
    num_round, remainder = H // abs(round_drop), H % abs(round_drop)
    remain_round = 0
    while remainder > 0:
        remainder += dl[remain_round]
        remain_round += 1
    # print(sum(dl), len(dl))
    # print(num_round)
    # print(remain_round)
    # print('n:', n)
    return n + num_round * len(dl) + remain_round

def main():
    H, n = map(int, input().split())
    dl = list(map(int, input().split()))
    # tick = time.time()
    print(solve(H, dl))
    # tock = time.time()
    # print('T:', round(tock - tick, 5))

if __name__ == "__main__":
    main()