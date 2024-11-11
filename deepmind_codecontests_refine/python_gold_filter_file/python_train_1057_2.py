a,b,z=list(map(int,input().split()))
q1=(a//z)+(b//z)
q2=(a+b)//z

if(q1==q2):
    print(q1,0)

else:
    print(max(q1,q2),z-max(a%z,b%z))




