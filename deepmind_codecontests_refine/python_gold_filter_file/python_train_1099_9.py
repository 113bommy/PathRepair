n = int (input())
lst = [8,4,2,6]
if n ==0:
    print("1")
elif n > 0:
    i = (n-1) %4
    print(lst[i])