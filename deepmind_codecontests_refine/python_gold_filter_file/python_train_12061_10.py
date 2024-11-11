N, W = map(int, input().split())  # N<=100, W<=10**9
w, v = [0] * N, [0] * N
for i in range(N):
    w[i], v[i] = map(int, input().split())  # すべての i=2,3,…,N について、w1 ≦ wi ≦ w1+3

#

def kaihou():
    monos_by_omosa = [[] for _ in range(4)]
    w0 = w[0]
    for i in range(N):
        monos_by_omosa[w[i] - w0].append(v[i])
    for i in range(4):
        monos_by_omosa[i].sort()
        monos_by_omosa[i].reverse()
    # print(monos_by_omosa)
    ans = 0
    for i in range(N + 1):
        if i > len(monos_by_omosa[0]):
            break
        w0i = (w0) * i
        if w0i > W:
            break

        for j in range(N + 1 - i):
            if j > len(monos_by_omosa[1]):
                break
            w1j = (w0 + 1) * j
            if w0i + w1j > W:
                break

            for k in range(N + 1 - i - j):
                if k > len(monos_by_omosa[2]):
                    break
                w2k  = (w0 + 2) * k
                if w0i + w1j + w2k > W:
                    break

                for l in range(N + 1 - i - j - k):
                    if l > len(monos_by_omosa[3]):
                        break
                    w3l = (w0 + 3) * l
                    if w0i + w1j + w2k + w3l > W:
                        break

                    val = sum(monos_by_omosa[0][:i])
                    val += sum(monos_by_omosa[1][:j])
                    val += sum(monos_by_omosa[2][:k])
                    val += sum(monos_by_omosa[3][:l])
                    ans = max(ans, val)
    return ans

print(kaihou())
