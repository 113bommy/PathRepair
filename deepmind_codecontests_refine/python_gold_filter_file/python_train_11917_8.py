num_of_cubes = int(input())
cubes = 1
last = 1
stage = 0
while num_of_cubes >= cubes:
    num_of_cubes -= cubes
    last += 1
    stage += 1
    cubes += last
print(stage)