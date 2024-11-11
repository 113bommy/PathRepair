n,k=input().split(' ')
n=int(n)
k=int(k)
count=0
nr=2*n
ng=5*n
nb=8*n
if nr%k!=0:
    count+=nr//k + 1
else:
    count+=nr//k
if ng%k!=0:
    count+=ng//k + 1
else:
    count+=ng//k
if nb%k!=0:
    count+=nb//k+1
else:
    count+=nb//k
 
print(count)