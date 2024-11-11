N, K = map(int,input().split())
A = list(map(int,input().split()))

ans = 0

for i in range(min(N,K)+1):
  for j in range(min(N,K)+1-i):
    if j == 0:
      st = A[:i]
    else:
      st = A[:i]+ A[-j:]
    st.sort(reverse = 1)
    for suteru in range(K - i - j+1):
      ans = max(ans, sum(st[:i+j-suteru]))
    
print(ans)