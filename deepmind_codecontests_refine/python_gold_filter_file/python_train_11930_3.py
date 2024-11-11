N, T, K, D = input().split(" ")

n, t, k, d = int(N), int(T), int(K), int(D)

T1 = int((d / t)) * k
T2 = n - k

print("YES") if T1 < T2 else print("NO")