for i in range(int(input())):
    candies = int(input())
    final =0
    if candies <=2:
        print(0)
    if candies>2:
        final = candies //2
        if candies%2==0 :
            final -=1
            print(final)
        else:
            print(final)