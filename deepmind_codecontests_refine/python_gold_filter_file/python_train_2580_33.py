h, w, n= [int(input()) for i in range(3)]
k = max(h, w)
ans = (n+k-1)//k
print(ans)