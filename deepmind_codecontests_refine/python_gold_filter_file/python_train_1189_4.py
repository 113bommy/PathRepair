n, m = map(int, input().split())
checker = True
if n >= m/2 - 1 and n <= m + 1:
    a = min(m//2, n)
    m -= 2*a
    n -= a
    answer = '110'*(a)
    a += 1
    if m < 3:
        answer += '1'*m
        a += m
    else:
        checker = False
    if n <= a:
        c = answer.count('11')
        answer = answer.replace('11', '101', min(c, n))
        if n - c == 2:
            answer = '0' + answer + '0'
        elif n - c == 1:
            answer = '0' + answer
        elif n - c > 2:
            checker = False
    else:
        checker = False
else:
    checker = False
print(answer if checker else -1)