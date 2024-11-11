n,*a=map(int,open(0).read().split())
for i in range(n,0,-1):a[i-1]=sum(a[i-1::i])%2
print(sum(a),*[i+1for i in range(n)if a[i]])