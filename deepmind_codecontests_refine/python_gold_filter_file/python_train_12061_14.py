from itertools import accumulate
N, W = map(int, input().split())
w_0, v_0 = map(int, input().split())
v_list = [[] for _ in range(4)]
v_list[0].append(v_0)

for _ in range(N - 1):
    w_in, v_in = map(int, input().split())
    v_list[w_in - w_0].append(v_in)
v_list = [[0] + list(accumulate(sorted(v, reverse=True))) for v in v_list]
ans = 0

#print(v_list)

for i in range(len(v_list[0])):
    for j in range(len(v_list[1])):
        for k in range(len(v_list[2])):
            for l in range(len(v_list[3])):
                if (i * w_0) + (j * (w_0 + 1)) + (k * (w_0 + 2)) + (l * (w_0 + 3)) <= W:
                    ans = max(ans, v_list[0][i] + v_list[1][j] + v_list[2][k] + v_list[3][l])
                else:
                    break
print(ans)

