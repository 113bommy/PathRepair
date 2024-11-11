def isComposite(n):
    # Corner cases
    if n <= 1:
        return False
    if n <= 3:
        return False

    # This is checked so that we can skip
    # middle five numbers in below loop
    if n % 2 == 0 or n % 3 == 0:
        return True
    i = 5
    while i * i <= n:

        if n % i == 0 or n % (i + 2) == 0:
            return True
        i = i + 6

    return False


n = int(input())
for i in range(4,n):
    if isComposite(i) and isComposite(n-i):
        print(str(i)+ " " + str(n-i))
        break