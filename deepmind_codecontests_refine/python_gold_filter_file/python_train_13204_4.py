a = input()
n = len(a)
cnt = [0]*(ord('z')-ord('a')+1)


res = 0
for s in a:
    idx = ord(s) - ord('a')
    res += cnt[idx]
    cnt[idx]+= 1
ans = (n*(n-1)/2)-res+1
print(int(ans))