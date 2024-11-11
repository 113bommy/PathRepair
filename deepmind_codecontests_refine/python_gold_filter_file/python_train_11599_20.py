accepted_vals = ["", "1", "14", "144"]
number = input()
i = -1
while i < len(number):
    cur_str = ""
    while i < len(number) - 1 and cur_str + number[i+1] in accepted_vals:
        cur_str += number[i+1]
        i += 1
    if cur_str == "":
        if i < len(number) - 1:
            print("NO")
        else:
            print("YES")
        break

