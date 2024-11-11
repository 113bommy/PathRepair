from itertools import permutations

notes = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"]
user_input = input().split(" ")
all_permutations = []

for p in permutations(user_input):
    all_permutations.append(list(p))


def reindex(s, e):
    new_notes = []
    start = notes.index(s)
    end = notes.index(e)
    for i in range(start, len(notes)):
        new_notes.append(notes[i])
    for i in range(0, start):
        new_notes.append(notes[i])
    return new_notes


def check(new_notes, new_permutations):
    if(new_notes.index(new_permutations[1]) - new_notes.index(new_permutations[0]) == 4):
        if(new_notes.index(new_permutations[2]) - new_notes.index(new_permutations[1]) == 3):
            return "major"
    elif(new_notes.index(new_permutations[1]) - new_notes.index(new_permutations[0]) == 3):
        if(new_notes.index(new_permutations[2]) - new_notes.index(new_permutations[1]) == 4):
            return "minor"
    else:
        return None


for i in range(6):
    check_user_input = check(reindex(all_permutations[i][0], all_permutations[i][2]), all_permutations[i])
    if(check_user_input == "major" or check_user_input == "minor"):
        print(check_user_input)
        break
    if(i == 5):
        if(check_user_input == None):
            print("strange")
