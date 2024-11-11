jojo=[int(x) for x in input().split()]
m=jojo[1]
n=jojo[0]
p=[int(x) for x in input().split()]
p.sort()
ss=[]



for i in range(m-n+1):
        
    dio=p[i+n-1]-p[i]
    ss.append(dio)

print(min(ss))
