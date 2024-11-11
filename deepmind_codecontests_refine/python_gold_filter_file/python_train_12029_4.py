def economy_game(n):
    if n % 1234 == 0 or n % 123456 == 0 or n % 1234567 == 0:
        return "YES"
    else:
        if n < 1234567:
            for i in range(int(n/123456)+1):
                r = n - (123456*i)
                if r % 1234 == 0:
                    return "YES"
        else:
            for i in range(int(n/1234567)+1):
                for j in range(int((n-1234567*i)/123456)+1):
                    r = n - (123456*j + 1234567*i)
                    if r % 1234 == 0:
                        return "YES"
    return "NO"
                
n = int(input())
print(economy_game(n))