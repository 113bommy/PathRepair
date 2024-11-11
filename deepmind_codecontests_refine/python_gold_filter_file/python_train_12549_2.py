num_of_buttons = int(input())
arr_of_buttons = list(map(int, input().split()))

def main():
    count = 0
    
    if num_of_buttons == 1:
        if arr_of_buttons[0] == 1:
            print("YES")
        else:
            print("NO")
        return
        
    
    for i in range(num_of_buttons):
    	if arr_of_buttons[i] == 0:
    		count += 1
    
    if count == 1:
    	print("YES")
    else:
        print("NO")
    return

if __name__ == "__main__":
    main()