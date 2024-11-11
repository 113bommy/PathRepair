n,m = [int(s) for s in input().split(" ")]
 
d = n // m
mod = n % m
ans = []
 
for i in range(m):
    if mod > 0:
        ans.append(d+1)
        mod -= 1
    else:
        ans.append(d)
 
print(" ".join(map(str,ans)))
    