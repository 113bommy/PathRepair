def cin():
    return list(map(int, input().split()))

N=int(10e5+5)
n,x=cin()
A=cin()
B=[0]*N
an=0
for i in A:
    an+=B[i^x]
    B[i]+=1

print(an)

        
