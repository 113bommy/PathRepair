#create a function that count numbers repeated in a array

def count_numbers_repeated(arr, n):
    arr = sorted(arr) 
    count = 0
    for i in range(n-1):
        if(arr[i] != arr[i+1]):
            count = count + 1
    return count

if __name__ == "__main__":

    n = int(input())
    rows = [None] * n 
    columns = [None] * n
    
    for i in range(n):
        ele = list(map(int, input().split()))
        rows[i] = ele[0]
        columns[i] = ele[1]
        
    f = count_numbers_repeated(rows, n) + 1
    c = count_numbers_repeated(columns, n) + 1
    
    if(f <= c):
        print(f)
    else:
        print(c)
        
