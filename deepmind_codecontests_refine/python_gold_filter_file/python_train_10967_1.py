n,k = list(map(int,input().split(" ")))
m = list(map(int,input().split(" ")))
peaks = list(m[i] for i in range(len(m)) if (i+1) % 2== 0)
peaks.sort(reverse=True)
# peaks = peaks[:k]
for i in range(2*n+1):
    if k > 0 and (i+1) % 2 == 0 and m[i] in peaks and m[i - 1] < m[i]-1 and m[i]-1 > m[i + 1]:
        k-=1
        m[i] -= 1
print(" ".join(list(map(str,m))))