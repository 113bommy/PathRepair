v='aeiou'
a=[v[i:]+v[:i]for i in range(5)]
k=int(input())
n=5
while n*n<k and k%n:n+=1
print(((''.join((x*n)[:n]for x in a)*k)[:k],-1)[n*n>k or k%n>0])