# A. Night at the Museum
# by hoanghust

current_pos = 0
rotations = 0
enlish_alpha = "abcdefghijklmnopqrstuvwxyz"

item = str(input())
if len(item) != 0 and  item.isalpha() and item.islower():
    # Check non-emtystring, contain only letters and lower case characters.
    for char in item:
        next_pos = enlish_alpha.index(char)

        if current_pos <= next_pos:
            rotations_clockwise = next_pos - current_pos
            rotations_countclockwise = current_pos + 25 - next_pos + 1
        else:
            rotations_clockwise = 25 - current_pos + next_pos + 1
            rotations_countclockwise = current_pos - next_pos

        if rotations_clockwise <= rotations_countclockwise:
            rotations_tmp = rotations_clockwise
        else:
            rotations_tmp = rotations_countclockwise
        
        rotations += rotations_tmp
        current_pos = next_pos

    print(rotations)
