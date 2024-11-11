try:
    option = input()
    s = input()
    arr = "qwertyuiopasdfghjkl;zxcvbnm,./"
    newS = ""

    if option == 'R':
        for char in s:
            for i in range(len(arr)):
                if arr[i] == char:
                    newS += arr[i-1]        

    if option == 'L':
        for char in s:
            for i in range(len(arr)):
                if arr[i] == char:
                    newS += arr[i+1]

    print(newS)

except Exception:
    pass
        
