n=int(input())
A=[]
F=[]
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        x=n//i
        A.append(x)
        A.append(i)
        F.append(True)
        F.append(True)
for i in range(len(A)):
    if A[i]!=1:
        if (int(A[i]**0.5))**2==A[i]:
            for j in range(len(A)):
                if A[j]%A[i]==0:
                    F[j]=False
B=[A[i] for i in range(len(A)) if F[i]]
print(max(B))