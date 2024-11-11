# https://codeforces.com/contest/910/problem/A
def way_to_home(n, max_dis, bin_str):
    i = 0
    steps = 0
    while i < n - 1:
        cnt = 0
        for j in range(i + max_dis, i, -1):
            if j < n:
                if bin_str[j] == 1:
                    i = j
                    steps += 1
                    cnt+=1
                    break
        if steps == 0:
            return -1
        elif cnt == 0:
            return -1
    return steps


a = list(map(int, input().split()))
n = a[0]
max_dis = a[1]
bin_str = list(map(int, input()))
x = way_to_home(n, max_dis, bin_str)
print(x)
