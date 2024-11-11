1,2,4,8,16
1,2,3,4,5,6,7,8,9,10

1,3,9,27
1,3,4,9,10,12,13,27

def log2(k):
    return k.bit_length() - 1

def calc(n,k):
    if k==0:
        return 0
    if k==1:
        return 1
    start=log2(k)
    #print(start)
    return calc(n, k-2**start)+n**start

T=int(input())
for t in range(T):
    n,k=map(int,input().split(' '))
    #print('\n')
    print(calc(n, k)%(10**9+7))