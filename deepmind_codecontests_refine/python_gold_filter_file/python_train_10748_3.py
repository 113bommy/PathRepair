test = int(input())
test_arr = []
for _ in range(test):
    n,x = map(int,input().split())
    arr = list(map(int,input().split()))
    odd_count = 0
    for a in arr:
        if a%2!=0:
            odd_count+=1
    even_count = n-odd_count
    if odd_count>=1:
        ans = 'Yes'
    else:
        ans = 'No'
    if x%2==0:
        if odd_count>=x:
            if even_count<=0:
                ans = 'No'
        elif odd_count<x and odd_count%2==0:
            if even_count<=(x-odd_count):
                ans = 'No'

    else:
        if odd_count%2==0 and odd_count<x:
            if even_count<=(x-odd_count):
                ans = 'No'
        # elif odd_count%2==0 and odd_count>x:
        #     if even_count<=0:
        #         ans = 'No'
    test_arr.append(ans)
for t in test_arr:
    print(t)