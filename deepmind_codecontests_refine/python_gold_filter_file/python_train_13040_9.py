def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        a_min = min(a)
        b_min = min(b)
        count = 0
        for i in range(n):
            count += max(a[i]-a_min, b[i]-b_min)

        print(count)


if __name__ == "__main__":
    main()

'''
3 5 6 => 3 5 6 => 
3 2 3 => 2 3 3 => 


2 3
1 2
'''
