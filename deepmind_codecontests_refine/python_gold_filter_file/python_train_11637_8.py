from collections import defaultdict
def solve(N,A,B):
    d1=defaultdict(int)
    d2=defaultdict(int)
    for i in range(N):
        d1[A[i]]+=1
        d2[B[i]]+=1
    for i in d1:
        if d1[i]+d2[i]>N:
            return "No",[]
    else:
        return "Yes",B[::-1]
    
if __name__ == "__main__":
    N=int(input())
    A=[int(i) for i in input().split()][:N]
    B=[int(i) for i in input().split()][:N]
    a,b=solve(N,A,B)
    print(a)
    if b!=[]:
        #print(a)
        k,z=0,N-1
        for i in range(N):
            if A[i]==b[i] and b[i]!=b[k]:
                b[i],b[k]=b[k],b[i]
                k+=1
            elif A[i]==b[i] and b[i]==b[k]:
                b[i],b[z]=b[z],b[i]
                z-=1
        z,k=0,N-1
        for i in range(N):
            if A[i]==b[i] and b[i]!=b[k]:
                b[i],b[k]=b[k],b[i]
                k-=1
            elif A[i]==b[i] and b[i]==b[k]:
                b[i],b[z]=b[z],b[i]
                z+=1
        print(*b)
