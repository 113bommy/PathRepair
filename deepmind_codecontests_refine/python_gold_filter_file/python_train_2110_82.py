def previous(n):

    n = n | (n >> 1)
    n = n | (n >> 2)
    n = n | (n >> 4)
    n = n | (n >> 8)
    n = n | (n >> 16)
    return n - (n>>1)

if __name__=='__main__':
    t=int(input())
    while(t>0):
        n=int(input())
        arr=[0]*n
        l=1
        k=previous(n)
        if(k>=2):
            arr[0]=k-1
        if(n>1):
            for i in range(1,n-k+2):
                arr[i]=k+i-1
            for i in range(n-k+2,n):
                arr[i]=l
                l=l+1
            for i in range(n):
                print(arr[i],end=' ')
            print()
        else:
            print('1')    
        t=t-1
        