n = int(input())
numbers = list(map(int, input().split()))
result = 0
for index in range(n):
    if(index > 0 and index < n - 1):
        if(((numbers[index] < numbers[index-1]) and (numbers[index] < numbers[index+1]))
               or ((numbers[index] > numbers[index+1]) and (numbers[index] > numbers[index-1]))):
            result +=1
print(result)