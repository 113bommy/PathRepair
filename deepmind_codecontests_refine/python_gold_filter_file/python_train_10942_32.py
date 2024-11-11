for _ in range(int(input())):
    s, a, b, c = map(int, input().split()) # s rupees available, c rupees is each choc bbar
    if c > s:
        print(0)
    elif s//c < a:
        print(s//c)
    elif s//c >= a:
        print(s//c + ((s//c)//a)*b)