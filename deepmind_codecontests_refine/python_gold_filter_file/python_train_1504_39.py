l=-2*(1000000000)
r=2*(1000000000)
n=int(input())
f=0
for i in range(n):
    s1,s2,s3=input().split()
    s2=int(s2)
    if((s1=="<" and s3=="Y") or (s1==">=" and s3=="N")):
        if(r>=s2):
            r=s2-1
            
    elif((s1==">" and s3=="Y") or (s1=="<=" and s3=="N")):
        if(l<=s2):
            l=s2+1
    
    elif((s1=="<=" and s3=="Y") or (s1==">" and s3=="N")):
        if(r>s2):
            r=s2
    
    elif((s1==">=" and s3=="Y") or (s1=="<" and s3=="N")):
        if(l<s2):
            l=s2
    
if(l<=r):
    print(l)
else:
    print("Impossible")