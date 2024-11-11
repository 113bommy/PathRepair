def main():
    m= 0
    input()
    for i in input().split(' '):
        result= m + int(i)
        if result > m:
            m=result
        print(result,end=' ')
main()