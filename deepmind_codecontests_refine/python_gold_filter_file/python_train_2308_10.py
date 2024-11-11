def find_second_max(list_of_numbers):
    max=list_of_numbers[0]
    second_max=list_of_numbers[1]
    if(second_max>max):
        second_max,max=max,second_max
    for i in range(2,len(list_of_numbers)):
        if(list_of_numbers[i]>=max):
            second_max=max
            max=list_of_numbers[i]
        elif list_of_numbers[i]>second_max: 
            second_max=list_of_numbers[i]
    return second_max

list_of_numbers=list(map(int,input().split(' ')))
d=list_of_numbers.pop()
second_max=find_second_max(list_of_numbers)
#print(second_max)
list_of_numbers.remove(second_max)
sum=0
#print(list_of_numbers)
for i in list_of_numbers:
    value=abs(i-second_max)
    if(value>d):
        sum=sum+0
    else:
        sum=sum+d-value
print(sum)