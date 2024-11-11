def main():
    k = int(input())
    for _ in range(k):
        n,x,t = map(int,input().split())
        mx = t//x
        #print(n,mx)
        if n < mx:
            ans = n*(n-1)//2
        else:
            ans = mx*(mx-1)//2 + (n-mx)*mx
        print(ans)



if __name__ == '__main__':
    main()