needs_flipping = ['a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9']
 
def flip(s):
    flip_count = 0
    for letter in s:
        if letter in needs_flipping:
            flip_count += 1
    return flip_count
    
print(flip(input()))
