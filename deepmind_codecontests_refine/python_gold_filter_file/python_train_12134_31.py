number=int(input())
list_of_numbers=list(map(int,input().split(' ')))
max_length_of_subarray=1
current_length_of_subarray=1
for i in range(1,number):
    #print('number is '+str(list_of_numbers[i]))
    if(list_of_numbers[i]<=list_of_numbers[i-1]):
        if(max_length_of_subarray<current_length_of_subarray):
            max_length_of_subarray=current_length_of_subarray
        current_length_of_subarray=0
    current_length_of_subarray=current_length_of_subarray+1
    #print('current_length_of_subarray is '+str(current_length_of_subarray))
if(max_length_of_subarray<current_length_of_subarray):
        max_length_of_subarray=current_length_of_subarray
print(max_length_of_subarray)