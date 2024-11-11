_ = input()
numbers = list(map(int,input().split()))
print('YES') if sum(numbers)%2==0 and max(numbers)<=sum(numbers)/2 else print('NO')