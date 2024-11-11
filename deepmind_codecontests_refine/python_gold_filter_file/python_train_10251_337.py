number=int(input())
if number%2==0:
    n=int(number/2)
    even_number=int(n*(n+1))
    odd_number=int(n**2)
    print(even_number-odd_number)
else:
    n = (number // 2)+1
    even_number = int(n * (n + 1))
    odd_number = int(n ** 2)
    last_odd=number+1
    print(even_number-odd_number-last_odd)