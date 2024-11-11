if __name__ == "__main__":
    x,y = list(map(int,input().split()))
    n = int(input())
    m = n
    result = float('inf')
    while m:
        i,j,t = list(map(int,input().split()))
        result = min( result , (((x-i)**2 + (y-j)**2) ** 0.5) / t )
        m = m - 1
    print(round(result,7)  ) 



