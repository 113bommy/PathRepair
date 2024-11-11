if __name__=='__main__':
    arr = input().split(' ')
    n = int(arr[0])
    m = int(arr[1])
    arr = input().split(' ')
    Lc = []
    Li = []
    for a in arr:
        Lc.append(int(a))
    arr = input().split(' ')
    for a in arr:
        Li.append(int(a))
    Lc.sort()
    Li.sort()
    ans = -1
    if Lc[-1]>=Li[0] or Li[0]<=2*Lc[0]:
        ans = -1
    else:
        ans=max(2*Lc[0],Lc[-1])
    print(ans)
