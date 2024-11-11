def solver():
    n=int(input())
    arr1,arr2,arr3=list(map(int,input().split())),list(map(int,input().split())),list(map(int,input().split()))
    ris=[0 for _ in range(n)]
    for x in range(n):
        if x!=0:die=x-1
        else:die=n-1
        ava=(x+1)%n
        if arr1[x]!=ris[die] and arr1[x]!=ris[ava]:
            ris[x]=arr1[x]
        elif arr2[x]!=ris[die] and arr2[x]!=ris[ava]:
            ris[x]=arr2[x]
        if arr3[x]!=ris[die] and arr3[x]!=ris[ava]:
            ris[x]=arr3[x]
    print(*ris)
for _ in range(int(input())):solver()