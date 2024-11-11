(_,K),*T=[map(int,t.split())for t in open(0)]
A,B=map(sorted,T)
d=[2**40,0]
exec("i=sum(d)//2;d[-sum(min(0,i//b-a)for a,b in zip(A,B[::-1]))>K]=i;"*41)
print(d[0])