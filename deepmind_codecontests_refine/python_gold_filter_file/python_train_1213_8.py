n,A,B= list(map(int, input().split(" ")))
x = list(map(int, input().split(" ")))
a,Sum,x,i=x[0],sum(x),list(sorted(x[1:],reverse=True)),0
while a*A/Sum<B:
    Sum=Sum-x[i]
    i+=1
print(i)
