row,line,waste,ask=map(int,input().split())
waste_array=[]
for i in range(waste):
    row_data,line_data=map(int,input().split())
    waste_array.append(((row_data-1)*line)+line_data)
waste_array=sorted(waste_array)

def binarySearchCount(arr, n, value):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)
        if (arr[mid] < value):
            count = mid + 1
            left = mid + 1
        else:
            right = mid - 1

    return count

for i in range(ask):
    row_data, line_data = map(int, input().split())
    key=(((row_data - 1) * line) + line_data)
    if key in waste_array:
        print("Waste")
    else:
        x=binarySearchCount(waste_array,len(waste_array) , key)
        result=(key-x)%3
        if result==1:
            print("Carrots")
        elif result==2:
            print("Kiwis")
        else:
            print("Grapes")


