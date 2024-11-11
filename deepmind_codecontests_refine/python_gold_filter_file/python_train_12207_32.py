
def max_gcd(n):
    if n<=3:
        return 1
    if n%2==0:
        return int(n/2)
    else:
        return int((n-1)/2)


if __name__ == '__main__':
    temp=int(input())
    for i in range(temp):
        num=int(input())
        print(max_gcd(num))