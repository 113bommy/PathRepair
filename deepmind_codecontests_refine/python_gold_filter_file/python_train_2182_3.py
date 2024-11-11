if __name__ == "__main__":
    while True:
        n = int(input())
        if n ==0:break
        nline = [i for i in range(1,n+1)]
        count = 0
        for i in range(n):
            for j in  range(i+1,n):
                if sum(nline[i:j]) > n:break
                if sum(nline[i:j]) == n:count +=1

        print(count)