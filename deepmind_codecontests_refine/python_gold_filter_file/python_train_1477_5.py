def bin_s(i,j,values,arr):
    while(i<j):
        m=(i+j)//2
        if(arr[m]>values):
            j=m-1
        else:
            i=m+1
    if(arr[i]>values):
        return i-1
    else:
        return i

store=[0]*(10**5)
for i in range(2,10**5):
    store[i]=i*(i-1)//2
for _ in range(int(input())):
    n=int(input())
    stack=[]
    i=0
    j=10**5-1
    while(n>0):
        j=bin_s(2,j,n,store)
        stack.append(j)
        n-=store[j]
    stack.append(0)
    l=len(stack)
    stack=stack[::-1]
    st="1"
    for i in range(1,len(stack)):
        st+="3"*(stack[i]-stack[i-1])
        st+="7"
    print(st)
