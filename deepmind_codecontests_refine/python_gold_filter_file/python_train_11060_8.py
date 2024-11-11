def main():
    t = int(input())

    while t != 0:
        n = int(input())

        k = n // 2
        if k & 1:
            print("NO")
            t-= 1
            continue
        print("YES")
        arr = [2*i for i in range(1,k+1)]
        arr2 = [2*i-1 for i in range(1,k)]
        arr2.append(3*k-1)

        ans = ""
        for x in arr + arr2:
            ans += str(x) + " "
        print(ans)
        
        t-= 1


if __name__ == "__main__":
    main()