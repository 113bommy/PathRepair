def main():
    Current_HP = int(input())
    remainder = Current_HP % 4
    Current_rank = ""
    if remainder == 1 :
        Current_rank = "A"
        added_number = 0
        print(str(added_number) +" "+ str(Current_rank))


    elif remainder == 2:
        Current_rank = "B"
        added_number = 1
        print(str(added_number) +" "+ str(Current_rank))


    elif remainder == 3:
        Current_rank = "A"
        added_number = 2
        print(str(added_number) +" "+ str(Current_rank))


    elif remainder == 0 :
        Current_rank = "A"
        added_number = 1
        print(str(added_number) +" "+ str(Current_rank))
if __name__ == '__main__': main()
