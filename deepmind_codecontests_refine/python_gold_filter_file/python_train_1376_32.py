n = int(input())
for case in range(n):
    word = input()
    if word[-2:] =='po':
        print("FILIPINO")
    elif word[-2:] =='su':
        print("JAPANESE")
    else:
        print("KOREAN")
        
        
