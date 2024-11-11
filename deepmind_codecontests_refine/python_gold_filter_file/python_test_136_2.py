problem_num = int(input())
for i in range(problem_num):
    n = int(input())
    arr = input().split()
    arr = [int(i) for i in arr]
    summation = sum(arr)
    div = summation % int((n*(n+1))/2)
    if div != 0:
        print('NO')
        continue
    if min(arr) < n * (n+1) / 2:
        print('NO')
        continue
    ai = []
    flag = False
    for j in range(n):
        a = 2 * summation/ n / (n+1) - (arr[j] - arr[j-1])
        if a < 0 or a % n != 0:
            flag = True
            print('NO')
            break

        a = int(a/n)
        ai.append(str(a))
    if flag:
        continue
    ai=' '.join(ai)
    print('YES')
    print(ai)