
tests = int(input())


for te in range(tests):
    A,B,C = list(map(int,input().split()))
    maxa = C+1000
    answer = 10**10
    arr = [-1 for i in range(3)]
    for a in range(1,maxa+1):
        for b in range(a,maxa+5,a):
            for c in range(b,maxa+5,b):
                k = abs(A-a) + abs(B-b) + abs(C-c)
                if(k < answer):
                    answer = k
                    arr[0] = a
                    arr[1] = b
                    arr[2] = c

    print(answer)
    print(*arr)
