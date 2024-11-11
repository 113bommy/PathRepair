if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n,x = map(int, input().split())
        a = list(map(int, input().split()))
        sumA = sum(a)
        if(sumA%x):
            print(n)
        else:
            l = -1
            r = n
            for idx,ele in enumerate(a):
                if ele%x != 0:
                    if l == -1:
                        l = idx
                    r = idx
            if l == -1:
                print("-1")
            else:
                print(n-min((l+1),(n-r)))
                
